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
import { loadScene } from "./sceneManager.js"
import { openTerminal } from "./terminal.js"
import { startChallenge } from "./challenges.js"
import { playCutscene } from "./cutscene.js"
import { hasFlag } from "./state.js"

export function handleTrigger(tile) {
  if (tile === "~") loadScene("camp")
  if (tile === "!") {
    const prompt = startChallenge("challenge_1")
    openTerminal(prompt)
  }
  if (tile === "*" && hasFlag("camp_access")) {
    playCutscene("assets/ascii/cutscenes/camp_unlocked.txt")
  }
}
