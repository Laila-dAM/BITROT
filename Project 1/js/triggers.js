import { loadScene } from "./sceneManager.js"
import { openTerminal } from "./terminal.js"

export function handleTrigger(tile) {
  if (tile === "~") loadScene("camp")
  if (tile === ">") openTerminal()
}
