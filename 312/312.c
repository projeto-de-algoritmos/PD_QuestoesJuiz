int maxCoins(int* nums, int numsSize) {
    // Adiciona balões fictícios com valor 1 nos extremos do array
    int *newNums = (int *)malloc((numsSize + 2) * sizeof(int));
    newNums[0] = newNums[numsSize + 1] = 1;
    for (int i = 1; i <= numsSize; i++) {
        newNums[i] = nums[i - 1];
    }

    // Cria uma matriz para armazenar os resultados intermediários
    int **dp = (int **)malloc((numsSize + 2) * sizeof(int *));
    for (int i = 0; i < numsSize + 2; i++) {
        dp[i] = (int *)calloc((numsSize + 2), sizeof(int));
    }

    // Calcula o máximo de moedas usando programação dinâmica
    for (int len = 1; len <= numsSize; len++) {
        for (int left = 1; left <= numsSize - len + 1; left++) {
            int right = left + len - 1;
            for (int k = left; k <= right; k++) {
                dp[left][right] = fmax(dp[left][right], 
                    newNums[left - 1] * newNums[k] * newNums[right + 1] +
                    dp[left][k - 1] + dp[k + 1][right]);
            }
        }
    }

    int result = dp[1][numsSize];

    // Libera a memória alocada
    free(newNums);
    for (int i = 0; i < numsSize + 2; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}