import Vue from 'vue'
import VueRouter, { RouteConfig } from 'vue-router'
import Home from '../views/Home.vue'

Vue.use(VueRouter)

const routes: Array<RouteConfig> = [
  {
    path: '/',
    name: 'Home',
    component: Home,
  },
  {
    path: '/ex1-ex2',
    name: 'Ex1Ex2',
    component: () => import('../views/ex1-ex2.vue'),
  },
]

const router = new VueRouter({
  routes,
})

export default router
