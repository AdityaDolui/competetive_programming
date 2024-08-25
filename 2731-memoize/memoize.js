/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    var check;
    let dp=[]
    return function(...args) {
        if (check === undefined) {
            check = args.length === 1;
        }
        const a=args[0];
        if(check){
            if(dp[a]!==undefined){
                return dp[a]
            }
             return dp[a]=fn(a)
        }else{
            const b=args[1];
            if(dp[a]!==undefined){
             if(dp[a][b]!==undefined){
                return dp[a][b]
            }
            }else dp[a]=[];
           return dp[a][b]=fn(a,b)
        
        }
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */