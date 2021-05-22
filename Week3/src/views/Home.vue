<template>
  <div class="home">
    <h1>STEP Homework Week3</h1>
    <div>
      各ページの入力欄に数式を入力し、「計算」を押すと計算結果が表示されます
    </div>
    <div>
      「テスト」を押すと、入力に関係なくテストが実行され、その結果が表示されます
    </div>
    <div>入力可能な文字は各入力欄の上に書いてあるとおりです</div>
  </div>
</template>

<script lang="ts">
import { Component, Vue } from 'vue-property-decorator'

@Component({
  name: 'Home',
})
export default class Home extends Vue {}
</script>
