(function() {"use strict";var __module = CC_EDITOR ? module : {exports:{}};var __filename = 'preview-scripts/assets/scripts/star.js';var __require = CC_EDITOR ? function (request) {return cc.require(request, require);} : function (request) {return cc.require(request, __filename);};function __define (exports, require, module) {"use strict";
cc._RF.push(module, '4a2edd1ELlCw6siPflnGUeK', 'star', __filename);
// scripts/star.js

"use strict";

//star.js
cc.Class({
        extends: cc.Component,

        properties: {
                // 星星和主角之间的距离小于这个数值时，就会完成收集
                pickRadius: 0,
                // 暂存 Game 对象的引用
                game: {
                        default: null,
                        serializable: false
                }
        },

        // LIFE-CYCLE CALLBACKS:

        // onLoad () {},

        start: function start() {}
}

// update (dt) {},
);

cc._RF.pop();
        }
        if (CC_EDITOR) {
            __define(__module.exports, __require, __module);
        }
        else {
            cc.registerModuleFunc(__filename, function () {
                __define(__module.exports, __require, __module);
            });
        }
        })();
        //# sourceMappingURL=star.js.map
        