/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    if(functions.length==0)return (x)=>(x)

    return functions.reduceRight(
        (prev,curr)=>{
            return (x)=>(curr(prev(x)))
        }

    )
    // return function(x) {
        
    // }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */