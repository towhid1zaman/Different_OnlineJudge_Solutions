/**
 * @return {Function}
 */
var createHelloWorld = function() {
    return function(...args) {
        return "Hello World";
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 *
 *Basic Syntax
The syntax is:

function f(a, b) {
  const sum = a + b;
  return sum;
}
console.log(f(3, 4)); // 7
 *
 */
