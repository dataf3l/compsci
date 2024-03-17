def getAlt(src, dest):
    if (src == 0 and dest == 1) or (src == 1 and dest == 0):
        return 2
    elif (src == 0 and dest == 2) or (src == 2 and dest == 0):
        return 1
    elif (src == 1 and dest == 2) or (src == 2 and dest == 1):
        return 0

def move(pieces, target_disk, source):
    if len(pieces) == 1: 
        print(f"Move disk {pieces[0]} from {source} to {target_disk}")
        return
    head = pieces[0]
    tail = pieces[1:]
    if tail:
        move(tail, getAlt(source, target_disk), source)
    move([head], target_disk, source)
    move(tail, target_disk, getAlt(source, target_disk))

def get_heaviest(s):
    temp = []
    heaviest = s.pop()
    temp.append(heaviest)
    while s:
        piece = s.pop()
        if piece > heaviest:
            heaviest = piece
        temp.append(piece)
    while temp:
        s.append(temp.pop())
    return heaviest

# Test example
n = 3  # Number of disks
pieces = list(range(n, 0, -1))  # Creates a list of disks, heaviest to lightest
move(pieces, 2, 0)  # Move from peg 0 to peg 2
