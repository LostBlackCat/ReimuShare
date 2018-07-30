"use strict";
cc._RF.push(module, '4a2edd1ELlCw6siPflnGUeK', 'star');
// scripts/star.js

"use strict";

//star.js
cc.Class({
        extends: cc.Component,

        properties: {
                // 星星和主角之间的距离小于这个数值时，就会完成收集
                pickRadius: 60,
                // 暂存 Game 对象的引用
                game: {
                        default: null,
                        serializable: false
                }
        },

        // LIFE-CYCLE CALLBACKS:、
        // onLoad () {},

        start: function start() {}
}

// update (dt) {},
);

cc._RF.pop();