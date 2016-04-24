#!/usr/bin/python3.4 -tt

import sys

word_dict = {}
tag_dict = {}
end_tag_dict = {}
trans_dict = {}
line_count = 0

def print_frequency ():
    print ("Words >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
    for word in word_dict:
        print ("1 %s %d" % (word, word_dict[word]))

    print ("Tag>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
    for tag in tag_dict:
        print ("2 %s %d" % (tag, tag_dict[tag]))

    print ("End Tag>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
    for tag in end_tag_dict:
        print ("3 %s %d" % (tag, end_tag_dict[tag]))

    print ("Trans>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
    for trans in trans_dict:
        temp = trans.split("!@#$%")
        print ("4 %s %s %d" % (temp[0], temp[1], trans_dict[trans]))


def write_frequency ():
    try:
        fd = open ("hmmmodel.txt", "w")

        t = "5" + " " + str(line_count) + "\n"
        fd.write(t)

        for tag in tag_dict:
            t = "2" + " " + tag + " " + str(tag_dict[tag]) + "\n"
            fd.write (t)

        for tag in end_tag_dict:
            t = "3" + " " + tag + " " + str(end_tag_dict[tag]) + "\n"
            fd.write (t)

        for word in word_dict:
            t = "1" + " " + word + " " + str(word_dict[word]) + "\n"
            fd.write (t)

        for trans in trans_dict:
            temp = trans.split("!@#$%")
            t = "4" + " " + temp[0] + " " + temp[1] + " "
            t += str(trans_dict[trans]) + "\n"
            fd.write (t)

    except FileNotFoundError:
        print ("Can't open the file for writing")


def calculate_frequency (flag, cur_tag_dict, word):
    global word_dict
    global end_tag_dict

    tag = word[-2:]

    if word in word_dict:
        word_dict[word] += 1
    else:
        word_dict[word] = 1

    if tag in cur_tag_dict:
        cur_tag_dict[tag] += 1
    else:
        cur_tag_dict[tag] = 1

    if flag == 2:
        if tag in end_tag_dict:
            end_tag_dict[tag] += 1
        else:
            end_tag_dict[tag] = 1
    #print ("%s, %s, %s" % (word, actual_word, tag))


def calculate_transition_prob (flag, first_tag, second_tag):

    if flag != 0:
        tag1 = first_tag[-2:]
    else:
        tag1 = first_tag
    tag2 = second_tag[-2:]
    temp = tag1 + "!@#$%" + tag2

    if temp in trans_dict:
        trans_dict[temp] += 1
    else:
        trans_dict[temp] = 1


def read_file (fd):
    global tag_dict
    global line_count

    for line in fd:
        words = line.split()
        if len(words) >= 1:
            calculate_transition_prob (0, "start_state_q0", words[0].strip())
        for i in range(0, len(words)-1):
            calculate_transition_prob (1, words[i].strip(), words[i+1].strip())
            calculate_frequency (1, tag_dict, words[i].strip())
        calculate_frequency (2, tag_dict, words[len(words)-1].strip())
        line_count += 1


def process_file (filename):
    try:
        fd = open (filename, "r")
        read_file (fd)
    except FileNotFoundError:
        print ("Can't open the file for reading")


def check_syntax ():
    if len (sys.argv) != 2:
        print ("Syntax: ./hmmlearn3.py /path/to/input")
        exit ()


def main():
    check_syntax ()
    process_file (sys.argv[1])
    #print_frequency()
    write_frequency()

if __name__ == "__main__":
    main()
