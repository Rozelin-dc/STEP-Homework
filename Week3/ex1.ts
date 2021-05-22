import { Token } from './type'
import * as utils from './utils'

export const main_ex1 = (input: string) => {
  const tokens = utils.tokenize(input, readOperator)
  if(tokens === null) return 'error'

}

/** () が無い式の計算 */
export const calculate = (tokens: Token[]) => {
  
}

/** +=/* 演算子の読み込み */
const readOperator = (input: string, idx: number) => {
  let token: Token | null = null
  switch (input[idx]) {
    case '+':
      token = { type: 'operator', value: '+' }
      break
    case '-':
      token = { type: 'operator', value: '-' }
      break
    case '*':
      token = { type: 'operator', value: '*' }
      break
    case '/':
      token = { type: 'operator', value: '/' }
      break
  }
  idx += 1
  return { token, idx }
}
