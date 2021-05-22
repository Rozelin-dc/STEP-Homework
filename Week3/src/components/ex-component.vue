<template>
  <div>
    <h2>{{ title }}</h2>
    <input v-model="input" />
    <button @click="result = calculate(input)">計算</button>
    <span>結果: {{ result }}</span>
  </div>
</template>

<script lang="ts">
import { Vue, Component, Prop } from 'vue-property-decorator'

@Component({
  name: 'ExComponent',
})
export default class extends Vue {
  @Prop({ required: true, type: String }) title!: string
  @Prop({ required: true, type: Function }) calculate!: (
    input: string
  ) => number | 'error'

  input = ''
  result: string | number = ''
}
</script>
