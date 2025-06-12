import json


filename = "combined_products.json"
with open(filename, "r", encoding="utf-8") as f:
    new_data = json.load(f)



keys = list(new_data.keys())


with open("new_data.json", "r", encoding="utf-8") as f:
    data = json.load(f)

for k in keys:
    if k not in data:
        data[k] = new_data[k]

with open("new_data.json", "w", encoding="utf-8") as f:
    json.dump(data, f, ensure_ascii=False, indent=2)
