import { loadText } from "./loader.js"
import { setScene } from "./state.js"
import { renderText } from "./renderer.js"

const scenes = {
  title: "assets/ascii/ui/title.txt",
  forest: "assets/ascii/maps/forest_start.map",
  camp: "assets/ascii/maps/camp_hub.map"
}

export function loadScene(name) {
  const path = scenes[name]
  if (!path) return

  fadeTransition(() => {
    setScene(name)
    loadText(path)
  })
}

export function fadeTransition(next) {
  renderText("\n\n...\n\n", false)
  setTimeout(next, 400)
}
