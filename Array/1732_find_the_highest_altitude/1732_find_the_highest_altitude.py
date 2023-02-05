class Solution:
    def largestAltitude(self, gain: list[int]) -> int:
        # 0 0-5 0-5+1 0-5+1+5 ... 
        # Prefix = 0 
        # Prefix sum
        prefix = 0 
        altitude = [prefix]

        for right in range(len(gain)):
            altitude.append(gain[right]+altitude[-1])
        print(altitude)
        return max(altitude)

        


        