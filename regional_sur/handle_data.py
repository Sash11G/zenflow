import json, os, sys

filename = "new_data.json"

with open(filename, "r", encoding="utf-8") as f:
    data = json.load(f)




def print_menu():
    cur_cat = ""
    cur_sub = ""
    cur_level = list(data.keys())
    cat = cur_level
    len_level = len(cur_level)
    inv_input = 0
    while True:
        os.system('clear')
        if cur_cat:
            info = data[cur_cat]
            if cur_cat == cat[0]:
                if cur_sub:
                    for item in info[cur_sub]: 
                        print(f"{item['Nombre']:<50}{item['Moneda']:>10}{item['Empaque']:>10}")
                        cur_sub = ""
                else:
                    for i, key in enumerate(cur_level):
                        print(f"{i + 1}: {key}")
                    print("\nPress 'q' to quit\n")
                    if inv_input == 1: 
                        sys.stdout.write("\033[F")
                        print("\aInvalid Choice! Try Again.")
                        inv_input = 0
                    idx = input("Choose: ")

            elif cur_cat == cat[1]:
                for item in info:
                    print(f"{item["Product"]:<30} {item["Unit"]:<5} {item["Calibre"]:<10} $ {item["Min Price"]:>5}")
                    cur_cat = ""
            elif cur_cat == cat[2]:
                for item in info:
                    print(f"{item["Specie"]}  {item["Min Price"]}")
                    cur_cat = ""
            cur_sub = ""
            input("\nPress Enter...")
            os.system('clear')

        for i, key in enumerate(cur_level):
            print(f"{i + 1}: {key}")
        print("\nPress 'q' to quit\n")
        if inv_input == 1: 
            sys.stdout.write("\033[F")
            print("\aInvalid Choice! Try Again.")
            inv_input = 0
        idx = input("Choose: ")

        try:
            if 0 <= int(idx) <= len_level:
                idx = int(idx)
        except:
            pass

        if type(idx) == int and 0 <= idx <= len_level: 
            os.system('clear')
            if cur_cat:
                cur_sub = cur_level[idx - 1]
                cur_level = list(data[cur_cat].keys())
                len_level = len(cur_level)

            else:
                cur_cat = cat[idx - 1]
                if idx == 1:
                    cur_level = list(data[cur_cat])
                    len_level = len(cur_level)
   
        elif idx.lower() == "q":
            exit(0)
        else:
            inv_input = 1

if __name__ == '__main__':
    

    print_menu()


