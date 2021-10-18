import random
import argparse

def generate_string(set):
    random_string = ''

    for i in range(10):
        random_int = random.randint(65, 90)
        random_string += (chr(random_int))

    set.add(random_string)

def generate_int(set, size):
    random_integer = random.randint(1, 3000000)
    
    set.add(random_integer)

def convert_set_to_list(set):
    toReturn = []

    for items in set:
        toReturn.append(items)
    
    return toReturn

if __name__ == "__main__":
    parser = argparse.ArgumentParser()

    parser.add_argument('type', help = "Type of data to generate")
    parser.add_argument('size', help = "Size of dataset", type = int, default=1)
    parser.add_argument('sortType', help = "Which way to sort if at all")
    parser.add_argument('duplicates', help = "Number of duplicates", type = float, default=0)

    args = parser.parse_args()

    dupes= float(args.duplicates)

    dupes_int_val = random.randint(1, 3000000)
    dupes_str_val = ''
    for i in range(10):
        strInt = random.randint(65, 90)
        dupes_str_val += (chr(strInt))

    size = int(args.size)
    first_size = int(args.size) * (1 - dupes)
    second_size = size - first_size
    list = []
    set = set()

    first_size = int(first_size)
    second_size = int(second_size)

    if args.type == 'string':
        if args.duplicates == 0:
            while len(set) < size:
                generate_string(set)
        else:
            while len(set) < first_size:
                generate_string(set)
            list = convert_set_to_list(set)
            for i in range(second_size):
                list.insert(random.randint(0, len(list)), dupes_str_val)


    if args.type == 'integer':
        if args.duplicates == 0:
            while len(set) < size:
                generate_int(set, size)
        else: 
            while len(set) < first_size:
                generate_int(set, size)
            list = convert_set_to_list(set)
            for i in range(second_size):
                list.insert(random.randint(0, len(list)), dupes_int_val)

    if args.duplicates == 0:
        list = convert_set_to_list(set)

    if (args.sortType == 'ascend'):
        list.sort()
    
    elif (args.sortType == 'descend'):
        list.sort(reverse=True) 
    
    else:
        random.shuffle(list)
    

    file = open("data_" + args.type + "_" + str(args.size) + "_" + args.sortType + "_" + str(args.duplicates) + ".txt", "w")
    for items in list:
        file.writelines(str(items)+'\n')

    file.close()