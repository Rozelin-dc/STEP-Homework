import { Token } from './type'

/** 入力を Token 型の配列に変換 */
export const tokenize = (
  input: string,
  readOperator: (
    input: string,
    idx: number
  ) => { token: Token | null; idx: number }
) => {
  const tokens: Token[] = ['+'] // ダミーの + を挿入
  let index = 0
  while (index < input.length) {
    if (!isNaN(+input[index])) {
      const { token, idx } = readNumber(input, index)
      tokens.push(token)
      index = idx
    } else {
      const { token, idx } = readOperator(input, index)
      if (token === null) return null
      tokens.push(token)
      index = idx
    }
  }
  return tokens
}

/** 数字読み込み */
const readNumber = (input: string, idx: number) => {
  let num = 0
  while (idx < input.length && !isNaN(+input[idx])) {
    num = num * 10 + +input[idx]
    idx += 1
  }
  if (input[idx] == '.') {
    let decimal = 0.1
    idx += 1
    while (idx < input.length && !isNaN(+input[idx])) {
      num += +input[idx] * decimal
      decimal /= 10
      idx += 1
    }
  }
  const token = num
  return { token, idx }
}
