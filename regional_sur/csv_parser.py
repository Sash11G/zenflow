
import re
import json

# Load raw text (replace with actual file read if needed)
with open("lista_precios.txt", "r", encoding="utf-8") as f:
    raw = f.read()

# Define known headers
headers = [
    "Legumbres y Otros", "Semillas", "Especias", "Especias (Continuación)", "Repostería",
    "Repostería (Continuación)", "Fruta Seca – Desecadas", "Azúcar – Infusiones", "Cereales",
    "Snacks y Galletas", "Fraccionados Cosecha Dorada", "Conserva de Frutas", "Conservas de Vegetales",
    "Palmitos", "Conserva de Pescados", "Conserva de Carnes", "Aceitunas", "Aceites y Vinagres",
    "Salsas y Aderezos", "Artículos de Limpieza Limpiamás", "Artículos de Limpieza Limppano",
    "Alimentos para Mascotas"
]

# Split the text into sections
split_data = re.split(f"(?=({'|'.join(map(re.escape, headers))}))", raw)

# Parse each section
cleaned_data = {}
i = 1
while i < len(split_data):
    section = split_data[i].strip()
    content = split_data[i + 1]
    rows = [line.strip() for line in content.splitlines() if re.match(r"^\w{2,5},", line)]

    items = []
    for row in rows:
        parts = [p.strip() for p in row.split(",")]
        if len(parts) >= 8:
            cod, nombre, cod_barra, desc, iva, moneda, unitario, empaque = parts[:8]
            items.append({
                "Cod": cod,
                "Nombre": nombre,
                "Cód. Barra": cod_barra,
                "Desc": desc,
                "IVA": iva,
                "Moneda": moneda,
                "Unitario": unitario,
                "Empaque": empaque
            })

    cleaned_data[section] = items
    i += 2

# Save as JSON
with open("productos_limpios.json", "w", encoding="utf-8") as f:
    json.dump(cleaned_data, f, ensure_ascii=False, indent=2)
