/**
 * @param {string} text
 * @return {number}
 */
var maxNumberOfBalloons = function(text) {
    let b = 0, a = 0,l =0, o =0,n=0;
    for(let e of text){
        if(e === 'b') b++;
        else if(e === 'a') a++;
        else  if(e === 'l') l++;
        else if(e === 'o') o++;
        else  if(e === 'n') n++;
    }
   l = Math.floor(l / 2);
   o = Math.floor(o / 2);
    return Math.min(b,a,l,o,n);
};