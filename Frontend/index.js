import Joystick from "./joystick.js"

export default {
    name: "index",
    components: {
        Joystick
    },
    data() {
        return {
            error: undefined,
            state: undefined,
            loading: false,
            linear: 0.0,
            angular: 0.0,
            set_velocity_interval_id: undefined
        };
    },
    watch: {
        error: function(new_value, old_value) {
            this.stopSetVelocityInterval();
        },
        state: function(new_value, old_value) {
            if (new_value !== undefined && old_value !== undefined && new_value !== old_value) {
                if (new_value === "Manual") {
                    this.startSetVelocityInterval();
                }
                else if (old_value === "Manual") {
                    this.stopSetVelocityInterval();
                }

                var self = this;

                async function setState() {
                    self.loading = true;

                    var query = new URLSearchParams({
                        state: new_value
                    });

                    await fetch("http://0.0.0.0:8080/set_state?" + query.toString(), {
                        method: "POST",
                        headers: {
                            "Content-Type": "text/plain; charset=UTF-8"
                        }
                    })
                    .then(function(response) {
                        console.log("SUCCESS: " + response);
                        
                        self.loading = false;
                    })
                    .catch(function(response) {
                        console.log("FAILURE: " + response);

                        self.loading = false;

                        self.error = response;
                    });
                }

                setState();
            }
        }
    },
    methods: {
        startSetVelocityInterval: function() {
            var self = this;

            function setVelocity() {
                var query = new URLSearchParams({
                    linear: self.linear,
                    angular: self.angular
                });

                fetch("http://0.0.0.0:8080/set_velocity?" + query.toString(), {
                    method: "POST",
                    headers: {
                        "Content-Type": "text/plain; charset=UTF-8"
                    }
                })
                .then(function(response) {
                    console.log("SUCCESS: " + response);
                })
                .catch(function(response) {
                    console.log("FAILURE: " + response);

                    self.error = response;
                });
            }

            this.set_velocity_interval_id = setInterval(setVelocity, 100);
        },
        stopSetVelocityInterval: function() {
            if (this.set_velocity_interval_id !== undefined) {
                clearInterval(this.set_velocity_interval_id);

                this.set_velocity_interval_id = undefined;
            }
        },
        onJoystickMoveAngular: function(x_value, y_value) {
            this.angular = x_value;
        },
        onJoystickMoveLinear: function(x_value, y_value) {
            this.linear = y_value;
        }
    },
    mounted() {
        var self = this;

        async function getState() {
            await fetch("http://0.0.0.0:8080/get_state", {
                method: "GET",
                headers: {
                    "Content-Type": "text/plain; charset=UTF-8"
                }
            })
            .then(function(response) {
                return response.text();
            })
            .then(function(response) {
                console.log("SUCCESS: " + response);
    
                self.state = response;
            })
            .catch(function(response) {
                console.log("FAILURE: " + response);

                self.error = response;
            });
        };

        getState();
    },
    template: `
        <v-app id="app">
            <v-container>
                <div v-if="error !== undefined">
                    <v-row>
                        <v-col>
                            <h1>
                                ASDR REST API returned the following error: 
                            </h1>
                        </v-col>
                    </v-row>
                    <v-row>
                        <v-col>
                            <h2>
                                {{ error }}
                            </h2>
                        </v-col>
                    </v-row>
                </div>
                <div v-else>
                    <v-row>
                        <v-col>
                        </v-col>
                        <v-col cols="10">
                            <v-row>
                                <v-col>
                                    <h1>
                                        Autonomous Surface Disinfection Robot
                                    </h1>
                                </v-col>
                            </v-row>
                            <v-row class="my-16">
                                <v-col>
                                    <v-btn-toggle tile group color="deep-purple accent-3" v-model="state">
                                        <v-btn value="Idle">
                                            Idle
                                        </v-btn>
                                        <v-btn value="Manual">
                                            Manual
                                        </v-btn>
                                        <v-btn value="Automatic">
                                            Automatic
                                        </v-btn>
                                    </v-btn-toggle>
                                </v-col>
                            </v-row>
                            <v-row class="my-16">
                                <v-col>
                                    <div v-if="loading === true">
                                        <v-row>
                                            <v-col>
                                                <v-progress-circular color="deep-purple" :size="50" :width="5" indeterminate>
                                                </v-progress-circular>
                                            </v-col>
                                        </v-row>
                                    </div>
                                    <div v-else-if="state === 'Idle'">
                                    </div>
                                    <div v-else-if="state === 'Manual'">
                                        <v-row>
                                            <v-col>
                                                <Joystick ref="joystick_angular" :x_max="1.0" :y_max="0.0" @joystickMove="onJoystickMoveAngular">
                                                </Joystick>
                                            </v-col>
                                            <v-col>
                                                <Joystick ref="joystick_linear" :x_max="0.0" :y_max="1.0" @joystickMove="onJoystickMoveLinear">
                                                </Joystick>
                                            </v-col>
                                        </v-row>
                                    </div>
                                    <div v-else-if="state === 'Automatic'">
                                    </div>
                                </v-col>
                            </v-row>
                        </v-col>
                        <v-col>
                        </v-col>
                    </v-row>
                </div>
            </v-container>
        </v-app>
        `
};