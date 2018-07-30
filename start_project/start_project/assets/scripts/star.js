//star.js
cc.Class
    (
    {
        extends: cc.Component,

        properties:
        {
            // 星星和主角之间的距离小于这个数值时，就会完成收集
            pickRadius: 0,
            // 暂存 Game 对象的引用
            game: {
                default: null,
                serializable: false
            }
        },

        // LIFE-CYCLE CALLBACKS:、
        // onLoad () {},

        start()
        {

        },

        // update (dt) {},
    }
    );
