import json

with open("new_data.json", "r") as f:
    data = json.load(f)


def trav(node, depth=0):
    if isinstance(node, dict):
        for key, val in node.items():
            print("  " * depth + f"{key} {'Category' if depth == 0   else 'Subcategory'}")
            trav(val, depth + 1)
    elif isinstance(node, list):
        print("  " * depth + f"{len(node)} Products")

trav(data)
