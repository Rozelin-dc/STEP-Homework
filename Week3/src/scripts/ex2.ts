import { mainEx1 } from './ex1'

export const mainEx2 = () => {
  let ans = 1
  if (mainEx1('1') !== ans) return 'NG'

  ans = 2
  if (mainEx1('1+1') !== ans) return 'NG'

  ans = 3
  if (mainEx1('1.0+2') !== ans) return 'NG'

  ans = -5
  if (mainEx1('1-2*3') !== ans) return 'NG'

  ans = 3
  if (mainEx1('2*3/2') !== ans) return 'NG'

  ans = 5.4
  if (mainEx1('1+2*3-4/5*2') !== ans) return 'NG'

  return 'OK'
}
