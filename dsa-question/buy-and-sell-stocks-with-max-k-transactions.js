/*
    so we will use dynamic programming with 2d matrix.
    where dp[i][j] will represent max profit with i transactions with
    first j elements of the array.
    for every element we will consider three cases:
    1) we don't do transaction or sell stocks on current element and simply take
        max of previous value with same no of transactions, that is dp[i][j-1]

    2) we do transaction with current element and take max of (previous values with one less transaction - thier price since we have to buy on that day and sell on current one)
        we will store it in maxWithTrans with every element so we don't have to traverse every time.
        it is basically max of all dp[i-1][x]-prices[x] where x goes from 0->(curr j-1)

    3) we take max of revious values but don't buy on that day and sell on current day cause 
        making exact k transactions is not cumpolsary, so we will take max of previous elements with one less trans
        , we will also store it in maxWithoutTrans.
        it is max of all dp[i-1][x] where x goes from 0 -> (curr j-1)
*/

function maxProfitWithKTransactions(prices, k) {
  const n = prices.length;

  let dp = new Array(k + 1);
  for (let i = 0; i <= k; i++) dp[i] = new Array(n);

  //initializing dp with 0
  for (let i = 0; i <= k; i++) {
    for (let j = 0; j < n; j++) dp[i][j] = 0;
  }

  for (let i = 1; i <= k; i++) {
    let maxWithoutTrans = dp[i - 1][0];
    let maxWithTrans = dp[i - 1][0] - prices[0];

    for (let j = 1; j < n; j++) {
      if (dp[i][j - 1] > dp[i][j]) dp[i][j] = dp[i][j - 1];
      if (maxWithoutTrans > dp[i][j]) dp[i][j] = dp[i][j];
      if (maxWithTrans + prices[j] > dp[i][j]) dp[i][j] = maxWithTrans + prices[j];

      if (dp[i - 1][j] > maxWithoutTrans) maxWithoutTrans = dp[i - 1][j];
      if (dp[i - 1][j] - prices[j] > maxWithTrans) maxWithTrans = dp[i - 1][j] - prices[j];
    }
  }
  return dp[k][n - 1];
}

// Do not edit the line below.
exports.maxProfitWithKTransactions = maxProfitWithKTransactions;
