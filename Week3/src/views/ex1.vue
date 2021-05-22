<template>
  <div>
    <ex-component title="宿題1" :calculate="runEx1" />
  </div>
</template>

<script lang="ts">
import { Vue, Component } from 'vue-property-decorator'
import ExComponent from '@/components/ex-component.vue'
import { mainEx1 } from '@/scripts/ex1'

@Component({
  name: 'Ex1',
  components: {
    ExComponent
  }
})
export default class extends Vue {
  runEx1 = mainEx1
}
</script>
