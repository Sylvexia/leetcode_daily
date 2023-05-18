// 2665. Counter II

type ReturnObj = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

function createCounter(init: number): ReturnObj {
    let cur = init;
    return {
        increment: function () {
            cur += 1;
            return cur;
        },
        decrement: function () {
            cur -= 1;
            return cur;
        },
        reset: function () {
            cur = init;
            return cur;
        }
    }

};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */