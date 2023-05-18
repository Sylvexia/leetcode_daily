// 2635. Apply Transform Over Each Element in Array

function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    let ret = arr;
    for (let i = 0; i < arr.length; i++) {
        ret[i] = fn(ret[i], i);
    }
    return ret;
};