import { loadScene } from "./sceneManager.js"
import { openTerminal } from "./terminal.js"
import { startChallenge } from "./challenges.js"

export function handleTrigger(tile) {
  if (tile === "~") loadScene("camp")
  if (tile === "!") {
    const prompt = startChallenge("challenge_1")
    openTerminal(prompt)
  }
}
