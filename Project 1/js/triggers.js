import { loadScene } from "./sceneManager.js"
import { openTerminal } from "./terminal.js"
import { startChallenge } from "./challenges.js"
import { playCutscene } from "./cutscene.js"
import { hasFlag, setFlag } from "./state.js"

export function handleTrigger(tile) {
  if (tile === "~") {
    loadScene("camp")
    return
  }

  if (tile === "!") {
    const prompt = startChallenge("challenge_1")
    openTerminal(prompt)
    return
  }

  if (tile === "*" && hasFlag("camp_access")) {
    playCutscene("assets/ascii/cutscenes/camp_unlocked.txt")
    return
  }

  if (tile === "?") {
    setFlag("camp_access")
    return
  }

  if (tile === "E") {
    setFlag("escaped")
    return
  }
}
