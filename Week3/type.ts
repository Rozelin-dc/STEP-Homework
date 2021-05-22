export type Operator = '+' | '-' | '*' | '/' | '(' | ')'

export interface Token {
  type: 'number' | 'operator',
  value: number | Operator
}
