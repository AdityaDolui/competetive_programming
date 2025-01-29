/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
      const INT_MIN = -Math.pow(2, 31);
    const INT_MAX = Math.pow(2, 31) - 1;

    let flag=x<0? true:false
    x=Math.abs(x)
    var ans=Number(x.toString().split("").reverse().join(""))

     ans= flag==true?0-ans:ans
      if (ans < INT_MIN || ans > INT_MAX) {
        return 0;
    }
     return ans
};