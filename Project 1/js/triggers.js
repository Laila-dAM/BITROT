import { loadScene } from "./sceneManager.js"

export function handleTrigger(tile) {
  if (tile === "~") loadScene("camp")
}
