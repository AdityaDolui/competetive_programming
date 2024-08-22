/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function(num) {
    let s=num.toString(2);
    let str="";
    //console.log(s);
    for(let ch in s){
    str+=s[ch]==='1'?'0':'1';
    }
   // console.log(str)
    return parseInt(str,2);
};