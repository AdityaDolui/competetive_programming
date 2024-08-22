/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function(num) {
    let s=num.toString(2);
    let str="";
    //console.log(s);
    for(let char of s){
    str+=char==='1'?'0':'1';
    }
   // console.log(str)
    return parseInt(str,2);
};