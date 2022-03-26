export default {
    name: "Joystick",
    props: {
        x_max: {
            type: Number,
            default: 1.0,
            coerce: function(str) { 
                return Math.min(1.0, Math.max(0.0, Number(str)));
            },
            validator: function(str) {
                return Number.isNaN(Number(str)) === false;
            }
        },
        y_max: {
            type: Number,
            default: 1.0,
            coerce: function(str) {
                return Math.min(1.0, Math.max(0.0, Number(str)));
            },
            validator: function(str) {
                return Number.isNaN(Number(str)) === false;
            }
        },
        internal_line_width: {
            type: Number,
            default: 2.0,
            coerce: function(str) {
                return Math.max(1.0, Number(str));
            },
            validator: function(str) {
                return Number.isNaN(Number(str)) === false;
            }
        },
        internal_fill_color: {
            type: String,
            default: "#cccccc",
            validator: function(str) {
                return CSS.supports("color", str) === true;
            }
        },
        internal_stroke_color: {
            type: String,
            default: "#888888",
            validator: function(str) {
                return CSS.supports("color", str) === true;
            }
        },
        external_line_width: {
            type: Number,
            default: 2.0,
            coerce: function(str) {
                return Number(str);
            },
            validator: function(str) {
                return Number.isNaN(Number(str)) === false;
            }
        },
        external_stroke_color: {
            type: String,
            default: "#444444",
            validator: function(str) {
                return CSS.supports("color", str) === true;
            }
        },
        auto_return_to_center: {
            type: Boolean,
            default: true,
            coerce: function(str) {
                return str === "true";
            }
        }
    },
    data() {
        return {
            context: undefined,
            pressed: 0,
            x_position: 0.0,
            y_position: 0.0
        };
    },
    methods: {
        radius: function() {
            return Math.min(this.$refs.canvas.width, this.$refs.canvas.height) * 0.25;
        },
        xCenter: function() {
            return this.$refs.canvas.width * 0.5;
        },
        yCenter: function() {
            return this.$refs.canvas.height * 0.5;
        },
        xMax: function() {
            return this.radius() * this.x_max;
        },
        yMax: function() {
            return this.radius() * this.y_max;
        },
        draw: function() {
            this.context.clearRect(0.0, 0.0, this.$refs.canvas.width, this.$refs.canvas.height);
            
            if (Math.abs(this.x_position - this.xCenter()) > this.xMax()) {
                this.x_position = this.xCenter() + this.xMax() * Math.sign(this.x_position - this.xCenter());
            }
    
            if (Math.abs(this.y_position - this.yCenter()) > this.yMax()) {
                this.y_position = this.yCenter() + this.yMax() * Math.sign(this.y_position - this.yCenter());
            }
    
            this.context.beginPath();
    
            this.context.arc(this.xCenter(), this.yCenter(), Math.max(Math.max(this.xMax() * 2.0, this.yMax() * 2.0), 10.0), 0.0, 2.0 * Math.PI, false);
            this.context.rect(this.xCenter() - Math.max(this.xMax() * 2.0, 10.0), this.yCenter() - Math.max(this.yMax() * 2.0, 10.0), Math.max(this.xMax() * 2.0, 10.0) * 2.0, Math.max(this.yMax() * 2.0, 10.0) * 2.0);
    
            this.context.closePath();
    
            this.context.lineWidth = this.external_line_width;
            this.context.strokeStyle = this.external_stroke_color;
    
            this.context.stroke();
    
            this.context.beginPath();

            this.context.arc(this.x_position, this.y_position, this.radius(), 0.0, 2.0 * Math.PI, false);
    
            this.context.closePath();
    
            this.context.fillStyle = this.internal_fill_color;
    
            this.context.fill();
    
            this.context.lineWidth = this.internal_line_width;
            this.context.strokeStyle = this.internal_stroke_color;
    
            this.context.stroke();
        },
        update: function() {    
            this.draw();
    
            const x_value = (this.x_position - this.xCenter()) / this.xMax();
            const y_value = (this.y_position - this.yCenter()) / this.yMax() * -1.0;
    
            this.$emit("joystickMove", x_value, y_value);
        },
        onTouchStart: function(event) {
            this.pressed = 1;
        },    
        onTouchMove: function(event) {
            if (this.pressed === 1) {
                this.x_position = event.targetTouches[0].pageX - this.$refs.canvas.offsetLeft;
                this.y_position = event.targetTouches[0].pageY - this.$refs.canvas.offsetTop;
    
                this.update();
            }
        },
        onTouchEnd: function(event) {
            this.pressed = 0;
    
            if (this.auto_return_to_center) {
                this.x_position = this.xCenter();
                this.y_position = this.yCenter();
            }
    
            this.update();
        },    
        onMouseDown: function(event) {
            this.pressed = 1;
        },
        onMouseMove: function(event) {
            if (this.pressed === 1) {
                this.x_position = event.pageX - this.$refs.canvas.offsetLeft;
                this.y_position = event.pageY - this.$refs.canvas.offsetTop;
    
                this.update();
            }
        },    
        onMouseUp: function(event) {
            this.pressed = 0;
    
            if (this.auto_return_to_center) {
                this.x_position = this.xCenter();
                this.y_position = this.yCenter();
            }
    
            this.update();
        }
    },
    setup() {
        var canvas = Vue.ref(null);

        return {
            canvas
        };
    },
    mounted() {
        this.$refs.canvas.width = this.$el.clientWidth;
        this.$refs.canvas.height = this.$el.clientHeight;

        this.context = this.$refs.canvas.getContext("2d");

        this.x_position = this.$refs.canvas.width * 0.5;
        this.y_position = this.$refs.canvas.height * 0.5;

        this.draw();
    },    
    template: `
      <div>
        <canvas ref="canvas" @touchstart="onTouchStart($event)" @touchmove="onTouchMove($event)" @touchend="onTouchEnd($event)" @mousedown="onMouseDown($event)" @mousemove="onMouseMove($event)" @mouseup="onMouseUp($event)">
        </canvas>
      </div>
    `
};