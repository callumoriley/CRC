# the crc_remainder and crc_check functions are not my code, they are from https://en.wikipedia.org/wiki/Cyclic_redundancy_check#Computation

def crc_remainder(input_bitstring, polynomial_bitstring, initial_filler):
    """Calculate the CRC remainder of a string of bits using a chosen polynomial.
    initial_filler should be '1' or '0'.
    """
    polynomial_bitstring = polynomial_bitstring.lstrip('0')
    len_input = len(input_bitstring)
    initial_padding = (len(polynomial_bitstring) - 1) * initial_filler
    input_padded_array = list(input_bitstring + initial_padding)
    while '1' in input_padded_array[:len_input]:
        cur_shift = input_padded_array.index('1')
        for i in range(len(polynomial_bitstring)):
            input_padded_array[cur_shift + i] \
            = str(int(polynomial_bitstring[i] != input_padded_array[cur_shift + i]))
    return ''.join(input_padded_array)[len_input:]

def crc_check(input_bitstring, polynomial_bitstring, check_value):
    """Calculate the CRC check of a string of bits using a chosen polynomial."""
    polynomial_bitstring = polynomial_bitstring.lstrip('0')
    len_input = len(input_bitstring)
    initial_padding = check_value
    input_padded_array = list(input_bitstring + initial_padding)
    while '1' in input_padded_array[:len_input]:
        cur_shift = input_padded_array.index('1')
        for i in range(len(polynomial_bitstring)):
            input_padded_array[cur_shift + i] \
            = str(int(polynomial_bitstring[i] != input_padded_array[cur_shift + i]))
    return ('1' not in ''.join(input_padded_array)[len_input:])

if __name__ == "__main__":
    input = "100101011"
    polynomial = "110101"
    remainder_crc = crc_remainder(input, polynomial, "0")
    print(remainder_crc)
    print(crc_check(input, polynomial, remainder_crc))

    numsVerified = 0
    for i in range(0,512):
        if crc_check(bin(i)[2:], polynomial, remainder_crc):
            print(bin(i)[2:])
            numsVerified += 1

    print(numsVerified)