import { setFlag } from "./state.js"

let current = null

const challenges = {
  challenge_1: {
    prompt: "Type: print('hello')",
    solution: "print('hello')",
    xp: 50,
    unlock: "camp_access"
  }
}

export function startChallenge(id) {
  current = challenges[id]
  return current.prompt
}

export function checkAnswer(input) {
  if (!current) return false
  return input.trim() === current.solution
}

export function getReward() {
  return current ? current.xp : 0
}

export function applyUnlock() {
  if (current && current.unlock) {
    setFlag(current.unlock)
  }
}

export function clearChallenge() {
  current = null
}
