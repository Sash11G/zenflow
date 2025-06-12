
import json, os, sys

def load_json(filename):
    with open(filename, "r", encoding="utf-8") as f:
        return json.load(f)

def clear():
    os.system("cls" if os.name == "nt" else "clear")

def detect_format(item):
    if "Nombre" in item and "Moneda" in item:
        return "{Nombre:<50}{Moneda:>10}{Empaque:>10}", ["Nombre", "Moneda", "Empaque"]
    elif "Product" in item:
        return "{Product:<30} {Unit:<5} {Calibre:<10} $ {Min Price:>5}", ["Product", "Unit", "Calibre", "Min Price"]
    elif "Specie" in item:
        return "{Specie:<30} $ {Min Price:>5}", ["Specie", "Min Price"]
    else:
        return str(item), []

def print_items(items):
    if isinstance(items, list) and items:
        fmt, keys = detect_format(items[0])
        for item in items:
            if keys:
                print(fmt.format(**item))
            else:
                print(item)
def choose_from_list(title, options):
    while True:
        clear()
        print(f"== {title} ==")
        for idx, option in enumerate(options, 1):
            print(f"{idx}. {option}")
        print("\nq. Quit / b. Back")
        choice = input("Choose: ").strip().lower()
        if choice == 'q': sys.exit(0)
        if choice == 'b': return None
        try:
            idx = int(choice) - 1
            if 0 <= idx < len(options):
                return options[idx]
        except:
            pass

def navigate(data):
    while True:
        main_cat = choose_from_list("Main Categories", list(data.keys()))
        if not main_cat: continue

        sub = data[main_cat]

        # Handle subcategories
        if isinstance(sub, dict):
            while True:
                sub_cat = choose_from_list(main_cat, list(sub.keys()))
                if not sub_cat: break
                clear()
                print_items(sub[sub_cat])

                input("\nEnter to continue...")
        else:
            clear()
            print_items(sub)
            input("\nEnter to continue...")


if __name__ == "__main__":
    data = load_json("new_data.json")
    navigate(data)

