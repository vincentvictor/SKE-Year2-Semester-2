I can't use N = 1024, so i use N = 500

#DCACHE#

This is the best result, with these setting,

# DCACHE configuration [c = 128KB, b = 128B, a = 8]
#
# DCACHE stats
#
# L1 Data Cache:
# Load-Hits:           1753758513   99.77%
# Load-Misses:            3976504    0.23%
# Load-Accesses:       1757735017  100.00%
# 
# Store-Hits:           253429202   99.99%
# Store-Misses:             27971    0.01%
# Store-Accesses:       253457173  100.00%
# 
# Total-Hits:          2007187715   99.80%
# Total-Misses:           4004475    0.20%
# Total-Accesses:      2011192190  100.00%

From many trials, i think the program requires a lot of memory allocations ; the program is quite big.
And the size of (i mean at every parts) memory shold be quite big, so the miss will not be occured that much.


#ICACHE#

This is the best result, with these setting, 

# ICACHE configuration [c = 16KB, b = 32B, a = 1]
#
# ICACHE stats
#
# L1 Inst Cache:
# Total-Hits:          3274252975  100.00%
# Total-Misses:             23036    0.00%
# Total-Accesses:      3274276011  100.00%

But for icache, i don't know why even with the lowest setting, there is no miss occured.