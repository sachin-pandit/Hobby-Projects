#!/usr/bin/python3.4 -tt


import sys
import math
from collections import defaultdict

tag_dict = {}
end_tag_dict = {}
line_count = 0


emission_dict = defaultdict (dict)
trans_dict = defaultdict (dict)
probability = defaultdict (dict)
backpointer = defaultdict (dict)


def print_dictionary():
    print ("Emission >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
    for key1 in emission_dict:
        for key2 in emission_dict[key1]:
            print ("%s %s %s" % (key1, key2, emission_dict[key1][key2]))

    print ("TAG >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
    for key in tag_dict:
        print ("%s %d" % (key, tag_dict[key]))

    print ("END TAG >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
    for key in end_tag_dict:
        print ("%s %d" % (key, end_tag_dict[key]))

    print ("Transition >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
    for key1 in trans_dict:
        for key2 in trans_dict[key1]:
            print ("%s %s %d" % (key1, key2, trans_dict[key1][key2]))


def fill_dictionary (cur_dict, words):
    key = words[1].strip()
    value = words[2].strip()
    cur_dict[key] = int(value)


def read_model_file (fd):
    global emission_dict
    global tag_dict
    global end_tag_dict
    global line_count
    global trans_dict

    for line in fd:
        words = line.split()
        flag = words[0].strip()
        if "1" == flag:
            keys = words[1].split("/")
            word = keys[0].strip()
            tag = keys[1].strip()
            value = int(words[2].strip())
            if tag in end_tag_dict:
                emission_dict[word][tag] = math.log(value/end_tag_dict[tag])
        elif "2" == flag:
            fill_dictionary (tag_dict, words)
            fill_dictionary (end_tag_dict, words)
        elif "3" == flag:
            key = words[1].strip()
            value = int(words[2].strip())
            if key in tag_dict:
                tag_dict[key] -= value
            else:
                tag_dict[key] = value
        elif "4" == flag:
            key1 = words[1].strip()
            key2 = words[2].strip()
            value = int(words[3].strip())
            if key1 in tag_dict:
                trans_dict[key1][key2] = math.log((value+1)/(tag_dict[key1]+len(tag_dict)))
            if key1 == "start_state_q0":
                trans_dict[key1][key2] = math.log((value+1)/(line_count+len(tag_dict)))
        elif "5" == flag:
            line_count = int(words[1].strip())


def smoothing():
    for tag in end_tag_dict:
        if tag not in trans_dict["start_state_q0"]:
            trans_dict["start_state_q0"][tag] = math.log (float(1)/(line_count+len(tag_dict)))

    for tag1 in end_tag_dict:
        for tag2 in end_tag_dict:
            if tag2 not in trans_dict[tag1]:
                trans_dict[tag1][tag2] = math.log (float(1)/(tag_dict[tag1]+len(tag_dict)))


def transition_prob (inner_tag, tag):
    if inner_tag in trans_dict:
        if tag in trans_dict[inner_tag]:
            res = trans_dict[inner_tag][tag]
        else:
            return -1000
    else:
        return -1000

    return res


def emission_prob (tag, word):
    if word in emission_dict:
        if tag in emission_dict[word]:
            res = emission_dict [word][tag]
        else:
            return math.log((0.00001)/line_count)
    else:
        return math.log((0.00001)/line_count)

    return res


def assign_tag (fdw, words):
    global probability
    global backpointer

    word = words[0].strip()
    for tag in end_tag_dict:
        if word in emission_dict:
            if tag in emission_dict[word]:
                probability[tag, 0] = trans_dict["start_state_q0"][tag] + emission_dict [word][tag]
                #print ("%s %s %d %s" % ("start_state_q0", tag, 0, probability[tag,0]))
            else:
                probability[tag, 0] = -1000
        else:
            probability[tag, 0] = trans_dict["start_state_q0"][tag]
        backpointer[tag, 0] = "start_state_q0"

    #print (probability)
    for t in range (1, len(words)):
        word = words[t].strip()
        if word in emission_dict:
            for tag in end_tag_dict:
                if tag in emission_dict[word]:
                    max_prob = -999999
                    max_tag = ""
                    for inner_tag in end_tag_dict:
                        temp = probability[inner_tag, t-1] + trans_dict[inner_tag][tag] + emission_dict[word][tag]
                        #print ("%s %s %d %s" % (inner_tag, tag, t, temp))
                        if temp > max_prob or max_prob == -999999:
                            max_prob = temp
                            max_tag = inner_tag
                    #print ("Max: %s %d %s" % (max_tag, t, max_prob))
                    probability[tag, t] = max_prob
                    backpointer[tag, t] = max_tag
                else:
                    #print ("%s %d %s" % (tag, t, -1000))
                    probability[tag, t] = -1000
                    backpointer[tag, t] = tag
        else:
            for tag in end_tag_dict:
                #print ("%s %d %s" % (tag, t, -1000))
                max_prob = -999999
                max_tag = ""
                for inner_tag in end_tag_dict:
                    temp = probability[inner_tag, t-1] + trans_dict[inner_tag][tag]
                    #print ("%s %s %d %s" % (inner_tag, tag, t, temp))
                    if temp > max_prob or max_prob == -999999:
                        max_prob = temp
                        max_tag = inner_tag
                #print ("Max: %s %d %s" % (max_tag, t, max_prob))
                probability[tag, t] = max_prob
                backpointer[tag, t] = max_tag

    max_prob = -999999
    max_tag = ""
    for tag in end_tag_dict:
        temp = probability [tag, len(words)-1]
        if temp > max_prob:
            max_prob = temp
            max_tag = tag

    tagged_sentence = words[len(words)-1].strip() + "/" + max_tag
    for t in reversed(range (len(words)-1)):
        temp = backpointer[max_tag, t+1]
        tagged_sentence = words[t].strip() + "/" + temp + " " + tagged_sentence
        max_tag = temp

    fdw.write(tagged_sentence + "\n")

def read_raw_file (fd):
    global probability
    global backpointer

    fdw = open ("hmmoutput.txt", "w")
    fdw = open ("hmmoutput.txt", "a")
    for line in fd:
        probability = defaultdict (dict)
        backpointer = defaultdict (dict)
        words = line.split()
        smoothing()
        assign_tag (fdw, words)


def process_model_file (filename):
    try:
        fd = open (filename, "r")
        read_model_file (fd)
    except FileNotFoundError:
        print ("Can't open the file for reading")

def process_raw_file (filename):
    try:
        fd1 = open (filename, "r")
    except:
        print ("Can't open the file for reading")
    read_raw_file(fd1)


def syntax_check():
    if len(sys.argv) != 2:
        print ("Syntax: ./hmmdecode.py /path/to/input")
        exit()


def main():
    syntax_check()
    process_model_file("hmmmodel.txt")
    #print_dictionary()
    process_raw_file (sys.argv[1])

if __name__ == "__main__":
    main()
