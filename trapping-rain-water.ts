function trap(height: number[]): number {
    // Find max height in list
    let max = 0;
    for (let i = 0; i < height.length; i++) {
        if(height[i] > max)
            max = height[i];
    }

    let result: number = 0;

    // Traverse an 'imaginative' matrix of the elevation map
    for (let y = 0; y < max; y++) {   
        let count: number = 0;
        let x = 0;
        // Move to first 'pixel/block' in row
        while (height[x] < y+1) x++; 
        // Count empty blocks from there
        for (; x < height.length; x++) {
            if(height[x] < y+1) {
                count++;
            } else { // Ensures the right wall is treated as empty
                result += count;
                count = 0;
            }
        }
    }

    return result;
};
