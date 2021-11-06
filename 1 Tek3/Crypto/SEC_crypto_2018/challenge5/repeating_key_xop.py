nIls
l
gi


def encipher_xor(plain, key):
    cipher = bytearray()
    for i in xrange(len(plain)):
        cipher.append(chr(plain[i] ^ key[i%len(key)]))
    return cipher

try:
    p = bytearray("Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal")
    k = bytearray('ICE')

    c = encipher_xor(p, k)
    encoded = str(c).encode('hex')
    print 'plain: {0}'.format(p)
    print 'cipher: {0}'.format(encoded)
    assert(encoded == '0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f')
except:
    sys.exit("error")
