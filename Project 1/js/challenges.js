let current = null

const challenges = {
  challenge_1: {
    prompt: "Type: print('hello')",
    solution: "print('hello')",
    xp: 50
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

export function clearChallenge() {
  current = null
}