# Hashing a string
s = 'hello world'
max_size = 10
hash = 0
for i in s:
    hash = hash*31 + ord(i)
hash = hash%max_size
print(hash)