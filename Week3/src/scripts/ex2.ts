import { mainEx1 } from './ex1'

/** 宿題1のテスト */
export const mainEx2 = () => {
  let ans = 1
  let result = mainEx1('1')
  if (result !== ans) return 'NG'

  ans = 2
  result = mainEx1('1+1')
  if (result !== ans) return 'NG'

  ans = 3
  result = mainEx1('1.0+2')
  if (result !== ans) return 'NG'

  ans = -5
  result = mainEx1('1-2*3')
  if (result !== ans) return 'NG'

  ans = 3
  result = mainEx1('2*3/2')
  if (result !== ans) return 'NG'

  ans = 5.4
  result = mainEx1('1+2*3-4/5*2')
  if (result !== ans) return 'NG'

  return 'OK'
}
