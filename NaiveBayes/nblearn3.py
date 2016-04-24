#!/usr/bin/python3.4 -tt

import sys
import os
import string
import collections
import re

truth_pos = {}
truth_neg = {}
decep_pos = {}
decep_neg = {}

truth_pos_wordcount = 0
truth_neg_wordcount = 0
decep_pos_wordcount = 0
decep_neg_wordcount = 0

total_unique_count = 0
total_keys = {}


def write_output():
    fwrite = open ("nbmodel.txt", "w")
    length = len (total_keys.keys())
    for i in total_keys:
        if (i in truth_pos):
            prob1 = (truth_pos[i] + 1) / (truth_pos_wordcount + total_unique_count)
        else:
            prob1 = (1)/(truth_pos_wordcount + total_unique_count)

        if (i in truth_neg):
            prob2 = (truth_neg[i] + 1) / (truth_neg_wordcount + total_unique_count)
        else:
            prob2 = (1)/(truth_neg_wordcount + total_unique_count)

        if (i in decep_pos):
            prob3 = (decep_pos[i] + 1) / (decep_pos_wordcount + total_unique_count)
        else:
            prob3 = (1)/(decep_pos_wordcount + total_unique_count)

        if (i in decep_neg):
            prob4 = (decep_neg[i] + 1) / (decep_neg_wordcount + total_unique_count)
        else:
            prob4 = (1)/(decep_neg_wordcount + total_unique_count)
        str1 = i + " " + str(prob1) + " " + str(prob2) + " "
        str1 += str(prob3) + " " + str(prob4) + str("\n")
        fwrite.write (str1)


def get_unique_count():
    global total_keys
    global total_unique_count

    total_keys = collections.Counter (truth_pos) + collections.Counter (truth_neg) + collections.Counter (decep_pos) + collections.Counter (decep_neg)
    total_unique_count = len (total_keys.keys())
    #print ("Total unique word count = %d" % (total_unique_count))


def class_wordcount ():
    global truth_pos_wordcount
    global truth_neg_wordcount
    global decep_pos_wordcount
    global decep_neg_wordcount

    truth_pos_wordcount = sum (truth_pos.values())
    truth_neg_wordcount = sum (truth_neg.values())
    decep_pos_wordcount = sum (decep_pos.values())
    decep_neg_wordcount = sum (decep_neg.values())
    #print ("LISTENNNNN LISTENNNNN LISTENNNNNL:\nTruthful positive = %d\nTruthful negative = %d\nDeceptive positive = %d\nDeceptive Negative = %d\n" % (truth_pos_wordcount, truth_neg_wordcount, decep_pos_wordcount, decep_neg_wordcount))



def check_and_increment (dict_var, word):
    #print ("Word = %s" % word)
    if word in dict_var:
        dict_var[word] += 1
    else:
        dict_var[word] = 1

def print_dictionary ():
    global truth_neg
    global decep_neg
    global truth_pos
    global decep_pos

    print ("TRUTHFUL NEGATIVE------------------------------\n")
    for i in truth_neg:
        if (len (i) != 0):
            print ("%s : %s" % (i, truth_neg[i]))

    print ("TRUTHFUL POSITIVE-------------------------------\n")
    for i in truth_pos:
        if (len (i) != 0):
            print ("%s : %s" % (i, truth_pos[i]))

    print ("DECEPTIVE POSITIVE------------------------------\n")
    for i in decep_pos:
        if (len (i) != 0):
            print ("%s : %s" % (i, decep_pos[i]))

    print ("DECEPTIVE NEGATIVE-------------------------------\n")
    for i in decep_neg:
        if (len (i) != 0):
            print ("%s : %s" % (i, decep_neg[i]))


def generate_dictionary (word, case_number):
    global truth_neg
    global decep_neg
    global truth_pos
    global decep_pos

    if (case_number == 1):
        check_and_increment (truth_neg, word)
    elif (case_number == 2):
        check_and_increment (decep_neg, word)
    elif (case_number == 3):
        check_and_increment (truth_pos, word)
    elif (case_number == 4):
        check_and_increment (decep_pos, word)

def read_file (filename, case_number):
    try:
        temp = ""
        fd = open (filename, "r")
        for line in fd:
            words = re.sub('[^A-Za-z]',' ',line).split()
            for word in words:
                '''
                for c in string.punctuation:
                    word = word.replace(c,"")
                '''
                word = word.lower()
                generate_dictionary (word, case_number)
                #print ("Word = %s" % word)
            #print ("%s" % (word))

    except FileNotFoundError:
        print ("Cant open the file\n")


def process_filename(subdir, file):
    if (file != ".DS_Store"):
        temp = os.path.join (subdir, file)
        #print ("File = %s" % (temp))
        if (("negative" in temp) and ("truthful" in temp)):
            #print ("\n%s is %s and %s" % (file, "negative", "truthful"))
            read_file (temp, 1)
            #print_dictionary ()
        if (("negative" in temp) and ("deceptive" in temp)):
            #print ("\n%s is %s and %s" % (file, "negative", "deceptive"))
            read_file (temp, 2)
            #print_dictionary ()
        if (("positive" in temp) and ("truthful" in temp)):
            #print ("\n%s is %s and %s" % (file, "positive", "truthful"))
            read_file (temp, 3)
            #print_dictionary ()
        if (("positive" in temp) and ("deceptive" in temp)):
            #print ("\n%s is %s and %s" % (file, "positive", "deceptive"))
            read_file (temp, 4)
            #print_dictionary ()

def main():
    if len(sys.argv) != 2:
        print ("Syntax: ./nblearn3.py <file_path>")
        exit()

    for subdir, dirs, files in os.walk (sys.argv[1]):
        if (len(files) != 0):
            for file in files:
                #print ("File name = %s\n" % file)
                process_filename (subdir, file)

    class_wordcount()
    get_unique_count()
    write_output()
    #print_dictionary ()

if __name__ == "__main__":
    main ()
