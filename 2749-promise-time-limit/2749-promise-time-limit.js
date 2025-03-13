/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
    
    return async function(...args) {
        return new Promise((resolve, reject) => {
            const val = fn(...args);
            const time = setTimeout(() => {
                reject('Time Limit Exceeded')
            }, t);
            
            val.then((result) => {
                clearTimeout(time);
                resolve(result);
            }).catch((error) => {
                clearTimeout(time);
                reject(error);
            });
        });
    };
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */