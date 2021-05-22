import { Token } from './type'
import * as utils from './utils'

export const mainEx1 = (input: string) => {
  const tokens = utils.tokenize(input.trim(), readOperator)
  if (tokens === null) return 'error'
  const ans = calculate(tokens)
  return ans
}

/** () が無い式の計算 */
export const calculate = (tokens: Token[]) => {
  const newTokens = calculateMultiplicationAndDivision(tokens)
  const ans = calculateAdditionAndSubtraction(newTokens)
  return ans
}

/** 掛け算と割り算のみ計算 */
const calculateMultiplicationAndDivision = (tokens: Token[]) => {
  const newTokens: Token[] = [tokens[0]]
  let prevOperatorFlag = false // ひとつ前の演算子が * か / だったら true
  for (let i = 2; i < tokens.length; i += 2) {
    if (tokens[i] === '+' || tokens[i] === '+') {
      if (!prevOperatorFlag) newTokens.push(tokens[i - 1])
      newTokens.push(tokens[i])
      prevOperatorFlag = false
      continue
    }
    if (tokens[i] === '*') {
      if (prevOperatorFlag) {
        ;(newTokens[newTokens.length - 1] as number) *= tokens[i + 1] as number
        continue
      }
      const newTokenValue =
        (tokens[i - 1] as number) * (tokens[i + 1] as number)
      newTokens.push(newTokenValue)
      prevOperatorFlag = true
    }
    if (tokens[i] === '/') {
      if (prevOperatorFlag) {
        ;(newTokens[newTokens.length - 1] as number) /= tokens[i + 1] as number
        continue
      }
      const newTokenValue =
        (tokens[i - 1] as number) / (tokens[i + 1] as number)
      newTokens.push(newTokenValue)
      prevOperatorFlag = true
    }
  }
  return newTokens
}

/** 足し算と引き算のみの式を計算する */
const calculateAdditionAndSubtraction = (tokens: Token[]) => {
  let ans = 0
  for (let i = 0; i < tokens.length; i += 2) {
    if (tokens[i] === '+') {
      ans += tokens[i + 1] as number
    }
    if (tokens[i] === '-') {
      ans -= tokens[i + 1] as number
    }
  }
  return ans
}

/** +=/* 演算子の読み込み */
const readOperator = (input: string, idx: number) => {
  let token: Token | null = null
  switch (input[idx]) {
    case '+':
      token = '+'
      break
    case '-':
      token = '-'
      break
    case '*':
      token = '*'
      break
    case '/':
      token = '/'
      break
  }
  idx += 1
  return { token, idx }
}
