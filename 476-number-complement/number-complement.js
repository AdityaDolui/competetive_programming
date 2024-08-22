/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function(num) {
    let s=num.toString(2);
    let str="";
    //console.log(s);
    for(let i=0;i<s.length;i++){
        if(s[i]=='1')str+='0';
        else str+='1';
    }
   // console.log(str)
    return parseInt(str,2);
};