/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const temp=[];
    for(let i=0;i<arr.length;i++){
        temp.push(fn(arr[i],i));
    }
    return temp
};