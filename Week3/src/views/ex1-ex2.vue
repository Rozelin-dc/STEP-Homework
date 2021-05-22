<template>
  <div>
    <ex-component
      title="宿題1・宿題2"
      valid-input-explanation="半角数字(小数含む)と+-*/が入力可能"
      :calculate="calculate"
      :test="test"
    />
  </div>
</template>

<script lang="ts">
import { Vue, Component } from 'vue-property-decorator'
import ExComponent from '@/components/ex-component.vue'
import { mainEx1 } from '@/scripts/ex1'
import { mainEx2 } from '@/scripts/ex2'

@Component({
  name: 'Ex1Ex2',
  components: {
    ExComponent,
  },
})
export default class extends Vue {
  calculate = mainEx1
  test = mainEx2
}
</script>
