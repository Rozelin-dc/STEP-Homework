## 使用言語

TypeScript(Node.js 12.18.0)

Vue.js(@vue/cli 4.5.10)

※WindowsではTypeScriptのコードはコマンドプロンプトからの入力を受け付けられない為、Vue.jsと組み合わせて、ブラウザ上で任意の入力を受け付けられるようにしました

## 概要

メインのコードは[./src/scripts](./src/scripts)以下にあります。

- [./src](./src)
  - [/components](./src/components)
    - [ex-component.vue](./src/components/ex-component.vue)：宿題1~3共通で使うvueコンポーネント
  - [/scripts](./src/scripts)
    - [type.ts](./src/scripts/type.ts)：共通で使う型を定義したファイル
    - [utils.ts](./src/scripts/utils.ts)：共通で使う関数を定義したファイル
    - [ex1.ts](./src/scripts/ex1.ts)：宿題1のコード
    - [ex2.ts](./src/scripts/ex2.ts)：宿題2のコード(宿題1のテスト)
  - [/views](./src/views)
    - [ex1-ex2.vue](./src/views/ex1-ex2.vue)：宿題1･2のページ

## 実行方法

### Project setup
```
npm install
```

### Compiles and hot-reloads for development
```
npm run serve
```

### Compiles and minifies for production
```
npm run build
```

### Lints and fixes files
```
npm run lint
```

### Customize configuration
See [Configuration Reference](https://cli.vuejs.org/config/).
