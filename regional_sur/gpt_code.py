
import json
import os
import sys

filename = "new_data.json"

with open(filename, "r", encoding="utf-8") as f:
    data = json.load(f)

def clear():
    os.system('cls' if os.name == 'nt' else 'clear')

def print_leaf(data_list):
    for item in data_list:
        for key, value in item.items():
            print(f"{key:<15}: {value}")
        print("-" * 40)
    input("\nPress Enter to return...")

def print_menu():
    stack = []  # Tracks the path taken
    current = data

    while True:
        clear()
        if isinstance(current, dict):
            options = list(current.keys())
            for i, key in enumerate(options):
                print(f"{i + 1}. {key}")
            print("\nPress 'b' to go back | 'q' to quit")

            choice = input("Choose: ").strip()
            if choice.lower() == 'q':
                break
            elif choice.lower() == 'b':
                if stack:
                    current = stack.pop()
                else:
                    print("Already at root.")
                    input("Press Enter...")
                continue

            try:
                idx = int(choice) - 1
                if 0 <= idx < len(options):
                    stack.append(current)
                    current = current[options[idx]]
            except:
                pass

        elif isinstance(current, list):
            clear()
            print_leaf(current)
            current = stack.pop() if stack else data

        else:
            print(f"Unsupported type: {type(current)}")
            break

if __name__ == '__main__':
    print_menu()
