/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let vec = [];
    for(let i = 0 ; i<arr.length; i++){
        if(fn(arr[i] , i)){
            vec.push(arr[i]);
        }
    }
    return vec;
};