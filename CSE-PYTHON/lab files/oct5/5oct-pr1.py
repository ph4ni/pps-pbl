# Take any decimal number and convert it into binary, octal, and hexadecimal.

decimal = int(input("Enter decimal value: "))

decimal_binary = bin(decimal)
decimal_oct = oct(decimal)
decimal_hex = hex(decimal)

print("for the given decimal ", decimal, ": ")
print("Binary: ", decimal_binary)
print("Octal: ", decimal_oct)
print("Hexadecimal: ", decimal_hex)

